import argparse
import json
import os
import sys
import xml.etree.ElementTree

ANNOXML_EXT = '.annoxml'
DAT_EXT = '.dat'
SPLIT_STR = 'split'
#LOW_BAND_STR = 'low'
HIGH_BAND_STR = 'high'

EVENT_TAG = 'event'
ANNOTATION_TAG = 'annotation'

HOT_TERM_LIST = 'hot'
COLD_TERM_LIST = 'cold'

STORAGE_DESIGNATION_FILE_SUFFIX = '_storage'


def main(argv):
    args = parse_args(argv)

    print(f'python annoxml_parser.py --i {args.i} --rules_json {args.rules_json}')

    file_list = []

    if os.path.isdir(args.i):
        files = [f for f in os.listdir(args.i) if os.path.isfile(os.path.join(args.i, f))]

        for filename in files:
            file_path = f'{args.i}/{filename}'
            file_list.append(os.path.abspath(file_path))
    else:
        file_list.append(args.i)

    for file in file_list:
        print(f'INFO: Working on file, {file}')

        if file.endswith(ANNOXML_EXT) and os.path.isfile(file):

            annotations = parse_annotations(file)
            rules = parse_terms(args.rules_json)
            hot_terms = rules[0]
            cold_terms = rules[1]

            if annotations and hot_terms and cold_terms:

                hot_cnt = 0
                cold_cnt = 0

                for annotation in annotations:
                    if annotation in hot_terms:
                        hot_cnt += 1
                        print(f'INFO: Term, "{annotation}", is HOT')
                    elif annotation in cold_terms:
                        cold_cnt += 1
                        print(f'INFO: Term, "{annotation}", is COLD')
                    else:
                        print(f'INFO: Term, "{annotation}", is ARCHIVAL')

                print('\nREPORT:')
                print(f'Hot terms: {hot_cnt}')
                print(f'Cold terms: {cold_cnt}')
                print(f'Archival terms: {len(annotations) - hot_cnt - cold_cnt}\n')

                designation = 'HOT' if hot_cnt else 'COLD' if cold_cnt else 'ARCHIVE'
                output_json(os.path.basename(file),designation, os.path.dirname(file))
                print(f'INFO: Finished processing, {file}\n')

    print('FINISHED!')


def parse_annotations(annotations_file):
    annotation_list = []
    try:
        with open(annotations_file) as input_xml:
            events = xml.etree.ElementTree.parse(input_xml).getroot()

            for event in events.iter(EVENT_TAG):
                annotation_list.append(event.find(ANNOTATION_TAG).text.lower())
    except IOError as e:
        print(f'ERROR: File, {annotations_file}, not found')
        print(e)

    return annotation_list


def parse_terms(rules_file):
    hot_terms = []
    cold_terms = []

    try:
        with open(rules_file) as rules_json:
            rules = json.load(rules_json)

            for hot_term in rules[HOT_TERM_LIST]:
                hot_terms.append(hot_term.lower())
            for cold_term in rules[COLD_TERM_LIST]:
                cold_terms.append(cold_term.lower())
    except IOError as e:
        print(f'ERROR: File, {rules_file}, not found')
        print(e)

    return hot_terms, cold_terms


def output_json(filename, designation, out_path):
    annoxml_filename = filename
    filename = filename.replace(ANNOXML_EXT, DAT_EXT)
    filename_tokens = filename.split('_')

    prefix = ''
    suffix = ''

    for i in range(0, len(filename_tokens)):
        token = filename_tokens[i]

        #if token.lower() not in (SPLIT_STR ,LOW_BAND_STR, HIGH_BAND_STR):
        if token.lower() not in (SPLIT_STR, HIGH_BAND_STR):
            prefix = f'{prefix}{token}_'
        elif token.lower() == SPLIT_STR:
            for j in range(i, len(filename_tokens)):
                if j < len(filename_tokens) - 1:
                    suffix = f'{suffix}{filename_tokens[j]}_'
                else:
                    suffix = f'{suffix}{filename_tokens[j]}'
            break

    base_filename = f'{os.path.splitext(annoxml_filename)[0]}{DAT_EXT}'
    #low_band_filename = f'{prefix}{LOW_BAND_STR}_{suffix}'
    high_band_filename = f'{prefix}{HIGH_BAND_STR}_{suffix}'

    out_dict = {
        'annoxml_filename' : annoxml_filename,
        'base_filename' : base_filename,
        #'low_band_filename' : low_band_filename,
        'high_band_filename' : high_band_filename,
        'designation' : designation
    }

    out_filepath = f'{out_path}/{os.path.splitext(filename)[0]}{STORAGE_DESIGNATION_FILE_SUFFIX}.json'
    out_filepath = os.path.abspath(out_filepath)

    try:
        with open(out_filepath, 'w') as json_output:
            #json.dump(out_dict, json_output)
            json_output.write(json.dumps(out_dict, indent=4))
    except IOError as e:
        print(f'ERROR: Unable to write output file, {out_filepath}')
        print(e)

    print(f'INFO: Successfully wrote file, {out_filepath}')


def parse_args(argv):
    parser = argparse.ArgumentParser(
        description='Annotation XML Parser',
        formatter_class=argparse.RawTextHelpFormatter)
    parser.add_argument('--i', required=True, default=None)
    parser.add_argument('--rules_json', required=True, default=None)

    return parser.parse_args(argv)


if __name__ == '__main__':
    RETURN_CODE = main(sys.argv[1:])
    exit(RETURN_CODE)
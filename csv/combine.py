import sys
from matplotlib.ticker import FormatStrFormatter, StrMethodFormatter
import matplotlib
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter
import numpy as np
import threading


def name_key(item):
    return item[0]


def load_csv(file_path: str):
    res = []
    with open(file_path, 'r') as txt_file:
        lines = txt_file.readlines()

        for line in lines:
            columns = line.split(", ")
            if not columns or columns[0] == "name":
                continue
            res.append([columns[0], columns[1]])

    res.sort(key=name_key)
    return res


def normalize(data):
    min_val = float(sys.maxsize)
    for item in data:
        min_val = min(min_val, float(item[1]))

    for item in data:
        item.append(float(item[1]) / min_val)


def thousands_separator(x, pos):
    """The two args are the value and tick position."""
    return f'{x:,.0f}'


def plot_test(suite_name, suit_data, valid_hash_table_names):

    matplotlib.rcParams["axes.axisbelow"] = True
    matplotlib.rcParams['figure.figsize'] = [16, 10.5]
    plt.style.use('dark_background')

    y_max = 0
    x = valid_hash_table_names
    y = []
    for name in valid_hash_table_names:
        val = suit_data['mean_ns'].get(name)
        if val is None:
            val = 0
        else:
            val = float(val)
        y.append(val)
        y_max = max(y_max, val)

    plt.grid(True, color='gray', linestyle='dashed')
    plt.grid(False, axis='x')

    plt.xticks(rotation=45, ha="right")

    log_scale = False
    if suite_name == 'CtorDtor':
        log_scale = True

    plt.title(str(suite_name))
    plt.ylabel("time (nanoseconds)")
    plt.ticklabel_format(useOffset=False, style='plain')

    bars = plt.bar(np.array(x), np.array(y), log=log_scale)

    bars[0].set_color('khaki')
    bars[1].set_color('moccasin')
    bars[2].set_color('salmon')
    bars[3].set_color('greenyellow')
    bars[4].set_color('plum')
    bars[5].set_color('orchid')
    bars[6].set_color('steelblue')
    bars[7].set_color('aquamarine')
    bars[8].set_color('goldenrod')
    bars[9].set_color('tomato')
    bars[10].set_color('teal')
    bars[11].set_color('dodgerblue')
    bars[12].set_color('rosybrown')

    # after plotting the data, format the labels
    formatter = FuncFormatter(thousands_separator)
    plt.gca().yaxis.set_major_formatter(formatter)

    png_name = suite_name + ".png"

    print("Save: " + png_name)
    plt.savefig(png_name, bbox_inches='tight')
    plt.show(block=False)
    plt.close()


def main():

    test01 = load_csv("test01.csv")
    normalize(test01)

    test02 = load_csv("test02.csv")
    normalize(test02)

    test03 = load_csv("test03.csv")
    normalize(test03)

    test04 = load_csv("test04.csv")
    normalize(test04)

    test05 = load_csv("test05.csv")
    normalize(test05)

    test06 = load_csv("test06.csv")
    normalize(test06)

    test07 = load_csv("test07.csv")
    normalize(test07)

    test08 = load_csv("test08.csv")
    normalize(test08)

    test09 = load_csv("test09.csv")
    normalize(test09)

    test10 = load_csv("test10.csv")
    normalize(test10)

    test_runs = [test01, test02, test03, test04, test05, test06, test07, test08, test09, test10]

    names = ["AbslFlatMap", "BoostUnordered", "Excalibur", "FollyF14", "LlvmDense", "LuauDense", "SkaFlatMap",
             "SkaUnorderedMap", "StdUnordered", "TslRobin", "GoogleDense", "BoostUnorderedFlat", "ParallelHashmap"]

    line = "HashName, "
    for test_run in test_runs:
        first_test_name = test_run[0][0]
        line += first_test_name.split(".")[0]
        line += ", "
    print(line)

    test_results = {}

    for name in names:
        line = name
        line += ", "
        for test_run in test_runs:
            found = False
            for test in test_run:
                test_name = test[0]

                name_and_hash = test_name.split(".")
                suite_name = str(name_and_hash[0])
                hash_name = str(name_and_hash[1])

                test_suite = test_results.get(suite_name)
                if test_suite is None:
                    test_suite = {'name': suite_name, 'normalized': {}, 'mean_ns': {}}
                    test_results[suite_name] = test_suite

                if test_name.find(name) >= 0:
                    test_suite['mean_ns'][hash_name] = test[1]
                    normalized = test[2]
                    test_suite['normalized'][hash_name] = normalized
                    line += str(normalized)
                    line += ", "
                    found = True
                    # absolute = float(test[1])
                    # print(test_name)
                    # print(absolute)
                    # print(normalized)
                    break
            if not found:
                line += ", "
        print(line)

    names.sort()

    for suite_name, suit_data in test_results.items():
        plot_test(suite_name, suit_data, names)

    return


main()



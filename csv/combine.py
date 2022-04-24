import sys


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
             "SkaUnorderedMap", "StdUnordered", "TslRobin"]

    line = "HashName, "
    for test_run in test_runs:
        first_test_name = test_run[0][0]
        line += first_test_name.split(".")[0]
        line += ", "
    print(line)

    for name in names:
        line = name
        line += ", "
        for test_run in test_runs:
            found = False
            for test in test_run:
                test_name = test[0]
                if test_name.find(name) >= 0:
                    normalized = test[2]
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

main()



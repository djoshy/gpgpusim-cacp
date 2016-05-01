#!/usr/bin/python

def find_ratio(contents):
    import re
    numbers=re.compile('[\d]+').findall(contents)
    num_kernel = int(numbers[0])
    i = 1
    min_ratio = 1
    total_ratio = 0
    num_ratio = 0
    for k in range(num_kernel):
        k_id = int(numbers[i])
        num_cta = int(numbers[i+1])
        num_warps = int(numbers[i+2])
        i = i + 3
        for j in range(num_cta):
            min_exec = min([int(x) for x in numbers[i:i+num_warps]])
            max_exec = max([int(x) for x in numbers[i:i+num_warps]])
            total_ratio += 1.0 * min_exec / max_exec
            num_ratio += 1
            if 1.0 * min_exec / max_exec < min_ratio:
                min_ratio = 1.0 * min_exec / max_exec
                min_all = min_exec
                max_all = max_exec
            i = i + num_warps

    print min_all, max_all, min_ratio
    print total_ratio / num_ratio


import sys
for file_name in sys.argv[1:]:
    print file_name
    f=open(file_name)
    contents=f.read()
    f.close()
    find_ratio(contents)
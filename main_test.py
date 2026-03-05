import pytest
import re

def regex_test(expected, lines):
    i = 0 ; match = 0
    for token in expected:
        for j in range(i, len(lines)):
            res = re.search(token, lines[j])
            if res is not None:
                i = j + 1
                match += 1
                break
        else:
            print(f'\033[91m Not Found: {token} \033[0m')
            assert False, f'Expect: {expected}'
    else:
        print(f'\033[91m match count: {match} \033[0m')
        assert match == len(expected), f'Expect: {expected}'


@pytest.mark.T1
def test_weight_le2_dist_le500():
    # weight=1.5, distance=300 -> rate=1.10, dist<=500 -> charge=1.10
    with open('result1.txt', 'r') as f:
        lines = f.readlines()
    print(lines)
    lines = [line.strip() for line in lines]
    regex_test([r'1\.10'], lines)


@pytest.mark.T2
def test_weight_le6_dist_gt500():
    # weight=5, distance=1000 -> rate=2.20, dist>500 -> charge=(1000/500)*2.20=4.40
    with open('result2.txt', 'r') as f:
        lines = f.readlines()
    print(lines)
    lines = [line.strip() for line in lines]
    regex_test([r'4\.40'], lines)


@pytest.mark.T3
def test_weight_le20_dist_gt500():
    # weight=15, distance=2500 -> rate=4.80, dist>500 -> charge=(2500/500)*4.80=24.00
    with open('result3.txt', 'r') as f:
        lines = f.readlines()
    print(lines)
    lines = [line.strip() for line in lines]
    regex_test([r'24\.0[0-9]'], lines)


@pytest.mark.T4
def test_invalid_weight():
    # weight=25 -> invalid weight
    with open('result4.txt', 'r') as f:
        lines = f.readlines()
    print(lines)
    lines = [line.strip() for line in lines]
    regex_test([r'[Ii]nvalid'], lines)

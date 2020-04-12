import os

with open('in.dat', 'rt') as fin:
    with open('out.dat', 'wt') as fout:
        for i, line in enumerate(fin):
            if i == 5164:
                fout.write('1\n')
            else:
                fout.write(line)

os.rename('out.dat', 'in.dat')


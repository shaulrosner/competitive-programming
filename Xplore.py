import json
from collections import defaultdict
n = int(input())
refs = {}
for _ in range(n):
    j = json.loads(input())
    authors = j['authors']['authors']
    for author in authors:
        aname = author['full_name']
        if aname not in refs:
            refs[aname] = [j['citing_paper_count']]
        else:
            refs[aname].append(j['citing_paper_count'])
info = []
for ref in refs:
    a = sorted(refs[ref], reverse=True)
    added = False
    for i, x in enumerate(a):
        if x < i+1:
            info.append((i, ref))
            added = True
            break
    if not added:
        info.append((i+1, ref))
info.sort(key=lambda x: (-x[0], x[1]))
for x in info:
    print("{0} {1}".format(x[1], x[0]))

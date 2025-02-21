f = 1
ss = set()
for i in range(1, 5982):
    f = f * i
    print(len(str(f)))
    # s = str(f)[:10]
    # if s in ss:
    #     print("trovato " + str(i) + " " + s)
    # ss.add(s)

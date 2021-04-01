def production(scan, stop):
    summ=0
    rate=0
    initial=scan[1]
    changed=False
    next=True
    for i in range (1,int(scan[2]+1)):
        if stop != 0 and i >= stop and i < stop + scan[4]:
            changed=True
            continue

        if changed:
            initial=90
            p=90
            rate=1+0.5*i
            next=False
            changed=False
        else:
            if next:
                rate=rate+1+0.5*i
                next=True
            p=initial-rate
        if(p<scan[3]):
            p=scan[3]
        #print(i,p)
        summ=summ+math.ceil(scan[0]*p*0.01)
    return int(summ)

# ==============================
import math
scan=input().split(" ")
scan=list(map(float,scan))

total = []

for i in range(0, int(scan[2]+1)):
    total.append(production(scan, i)) # i = 換羽開始的日期
#print(total)
index = 0
biggest = 0
for i in range(0, len(total)):
    if total[i] > biggest:
        biggest = total[i]
        index = i
print("-1" if index == 0 else index, ",", biggest, sep="")

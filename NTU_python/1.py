time_arr = input()
time_dep = input()
isNTU = input()

hh_arr = int(time_arr[0:2])
mm_arr = int(time_arr[3:5])

hh_dep = int(time_dep[0:2])
mm_dep = int(time_dep[3:5])

minutes = 0

# check if time exceed 23:59
if hh_dep < hh_arr :
    hh_dep = 23
    mm_dep = 59
    
if hh_dep == hh_arr :
    if mm_dep < mm_arr:
        hh_dep = 23
        mm_dep = 59

# convert hours to minutes

while hh_arr <= hh_dep :
    if hh_arr != hh_dep:
        while mm_arr < 60:
            minutes += 1
            mm_arr += 1
            if mm_arr == 60:
                mm_arr = 0
                hh_arr += 1
                break
    else:
        if mm_arr < mm_dep:
            minutes += 1
            mm_arr += 1
        else:
            break

money = 0

if isNTU == "Y":
    minutes = minutes - 30
    while minutes >= 0:
        money = money + 10
        minutes = minutes - 30

else:
    while minutes >= 0:
        money = money + 20
        minutes = minutes - 30
print(money)

mark=[".",":",";",",","43"]

ss=input()
while ss!="END":
    ss=ss.strip()
    s=""
    i=0
    while i <len(ss):
        count=0
        for j in mark:
            if ss[i]==j and i < len(ss)-1:
                if ss[i+1]!=j:
                    while ss[i+1]==" ":
                        i=i+1
                    s=s+j+" "
                    break
                else:
                    break
            count=j
        if i<(len(ss)-2):
            if ss[i] == "藏" and ss[i+1] == "身" and ss[i+2] == "地":
                s=s+"\藏身地\\"
                i=i+2
                #print("i",i)
                count=0
            elif count=="43":
                s=s+ss[i]
        elif count=="43":
            s=s+ss[i]
        i=i+1
        #print("ii",i)
    print(s)
    ss=input()

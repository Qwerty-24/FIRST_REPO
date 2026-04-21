a = list(map(str, input().split('_')))
ag = ""
pri = ""
for i in range(0, len(a)):
    if (a[i] == "AGENT"):
        ag = a[i+1].capitalize()

    if (a[i] == "URGENT" or a[i] == "DANGER"):
        pri = "HIGH"
    else:
        pri = "LOW"

print(f"Agent: {ag}. Priority: {pri}.")

    
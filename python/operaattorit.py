oldprice = float(input("Input the items price (ALV Included): "))

totalwoalv = (oldprice / (1 + (24 / 100)))
total = (totalwoalv * (25.5 / 100) + totalwoalv)

print("The new total with 25,5% alv is :")
print(round(total,2))
print("Without it is :")
print(round(totalwoalv,2))
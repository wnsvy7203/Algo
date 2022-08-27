D, H, W = map(int, input().split())
print(int(((D**2) / (1+((W/H)**2))) ** (1/2)), int(((D**2) / (1+((W/H)**2)) * ((W/H)**2)) ** (1/2)))
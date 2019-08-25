def findCheapestPrice(n, flights, src, dst, k):
    if src == dst:
        return 0
    if k < 0:
        return 10000000
    cost = []
    for index in range (0,n):
        if flights[index][0] == src:
            hopCost = flights[index][2]
            remainingCost = findCheapestPrice(n,flights,flights[index][1], dst, k-1)
            cost.append(hopCost+remainingCost)
    return min(cost)


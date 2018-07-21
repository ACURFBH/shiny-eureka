# hw 4 question 1
import numpy.random as npr
import matplotlib.pyplot as plt
deduct = 0.003333# deduction that can possibly be made
finalTime = 260# number of days that will pass
dt = 1# each day that will pass
n = finalTime# number of random variables needed

# for part 1
val1 = 1000000
mu1 = 0.001949
sigma1 = 0.002018
nums = npr.normal(mu1, sigma1, n)# generate the tuple n normally distributed random variable
t1 = 0
x1 = []
y1 = []
print("generate points for graph 1")
while t1 < finalTime :
    # input values into data
    x1.append(t1)
    y1.append(val1)
    #value changes
    val1 += nums[t1]
    if nums[t1] > 0:
        val1 -= (deduct * nums[t1])
    #toward the next step
    t1 += dt
#plot the graph
print("plot points for graph 1")
plt.plot(x1, y1, color = "red")
plt.title("Positive mean")
plt.ylabel("Stock Value")
plt.xlabel("days")
plt.show()
plt.close()
# value after 260 days
print("value after 260 days for graph 1 =", y1[259])

# for part 2
val2 = 1000000
mu2 = -0.001989
sigma2 = 0.006464
nums = npr.normal(mu2, sigma2, n)# generate the tuple n normally distributed random variable
t2 = 0
x2 = []
y2 = []
print("generate points for graph 2")
while t2 < finalTime :
    # input values into data
    x2.append(t2)
    y2.append(val2)
    # value changes
    val2 += nums[t2]
    if nums[t2] > 0:
        val2 -= (deduct * nums[t2])
    # toward the next step
    t2 += dt
# plot the graph
print("graph points for graph 2")
plt.plot(x2, y2, color = "blue")
plt.title("Negative mean")
plt.ylabel("Stock Value")
plt.xlabel("days")
plt.show()
plt.close()
# value after 260 days
print("value after 260 days for graph 2 =", y2[259])

# for part 3: graph both graphs together
print("plot graph 3")
plt.plot(x1, y1, color = "red")
plt.plot(x2, y2, color = "blue")
plt.title("Postitve mean versus Negative mean")
plt.ylabel("Stock Value")
plt.xlabel("days")
plt.show()
plt.close()
# part 4 right after graphing each graph
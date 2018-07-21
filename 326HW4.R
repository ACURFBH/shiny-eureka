# HW 4 question 1
# information for the problem
deduct <- 0.003333
final_time <- 260
dt <- 1 # each trading day is denoted dt
n <- final_time/dt

# Problem 1, part 1: compute and graph for investment value at the end of 260 days
val1 <- 1000000
mu1 <- 0.001949
sigma1 <- 0.002018
nums1 <- rnorm(n, mu1, sigma1)# nomally distributed random variable
t1 <- 0
x1 <- c()
y1 <- c()
while(t1 < final_time){
  # input values into data
  x1 <- c(x1, t1)
  y1 <- c(y1, val1)
  # toward the next step
  t1 <- t1 + dt
  # perform operation on val
  val1 <- (val1 + nums1[t1/dt])
  if(nums1[t1/dt] > 0){
    val1 <- (val1 - (deduct * nums1[t1/dt]))# deduction from the quantity gained
  }
}
plot(x1,y1, type = "l", col = "red")

# Problem 1, part 2: compute and graph for investment value at the end of 260 days
val2 <- 1000000
mu2 <- -0.001989
sigma2 <- 0.006464
nums2 <- rnorm(n, mu2, sigma2)# generate nomally distributed random variable
t2 <- 0
x2 <- c()
y2 <- c()
while(t2 < final_time){
  # input values into dataset
  x2 <- c(x2, t2)
  y2 <- c(y2, val2)
  # toward the next step
  t2 <- t2 + dt
  # perform operation on val
  val2 <- (val2 + nums2[t2/dt])
  if(nums2[t2/dt] > 0){
    val2 <- (val2 - (deduct * nums2[t2/dt]))# deuction from the quantity gained
  }
}
plot(x2,y2, type = "l", col = "blue")

# Problem 1, part 3: graph b0th graphs together
plot(x1,y1, type = "l", col = "red")
lines(x2,y2, type = "l", col = "blue")

# Problem 1, part 4: the final portfolio values after 260 days
val1# final value for the first graph
val2# final value for the second graph
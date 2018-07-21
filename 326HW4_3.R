# varibles for this problem
riverWidth <- 1000
initialCurrent <- 10
stepSize <- 0.0025# step size

# functions for this problem
w <-function(q, v_0, a){
  if(a == 0){
    return(0)
  }
  4 * v_0 * (q/a) * (1 - (q/a))
}
f <- function(trig1, trig2){
  if(trig1 == 0){
    return(0)
  }
  trig1 / sqrt((trig1^2) + (trig2^2))
}

a = riverWidth
v_0 = initialCurrent
v_b = 5
dt = 1# 0.0025 takes too long wtf???
x <- a
y <- 0
xvals <- c()
yvals <- c()
t <- 0
print("setting coordinates")
while(x > 0){
  xvals <- c(xvals, x)
  yvals <- c(yvals, y)
  dx <- v_b * f(x,y) * dt
  dy <- (v_b * f(y,x) * dt) + w(x, v_0, a)
  x <- x - dx
  y <- y + dy
  t <- t + dt
}
print("Coordinates set")
plot(xvals,yvals)
print("graph plotted")

# to solve the problem
Question3 <- function(a, v_0, v_b, dt){
  x <- a
  y <- 0
  xvals <- c()
  yvals <- c()
  t <- 0
  print("setting coordinates")
  while(x > 0){
    xvals <- c(xvals, x)
    yvals <- c(yvals, y)
    dx <- v_b * f(x,y) * dt
    dy <- (v_b * f(y,x) * dt) + w(x, v_0, a)
    x <- x - dx
    y <- y + dy
    t <- t + dt
  }
  print("Coordinates set")
  plot(xvals,yvals)
  print("graph plotted")
}

# when boat speed is 5
Question3(riverWidth, initialCurrent, 5, 0.0025)
initialCurrent

# when boat speed is 10
Question3(riverWidth, initialCurrent, 10, 0.0025)

# when boat speed is 15
Question3(riverWidth, initialCurrent, 15, 0.0025)

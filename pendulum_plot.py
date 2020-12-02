import math
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# read setup data
file = open("input.txt")
data = file.readline()[:-1].split()
file.close()

mass = float(data[2])
moi  = float(data[3])
dist = float(data[4])

time, theta, p = np.loadtxt("output.txt",delimiter=",",usecols=(0,1,2),unpack=True)

fig, ax = plt.subplots(1,2,figsize=(12,5))
def animate(t):
    ax[0].clear()
    ax[1].clear()
    ax[0].set_xlim(-1.1*dist,1.1*dist)
    ax[0].set_ylim(-1.1*dist,1.1*dist)
    ax[0].plot([0,dist*math.sin(theta[t])],[0,-dist*math.cos(theta[t])],color="brown")
    ax[0].scatter([0],[0])

    circle = plt.Circle((dist*math.sin(theta[t]),-dist*math.cos(theta[t])),0.08*dist,color='brown')
    ax[0].add_artist(circle)

    ax[1].set_xlim(-0.2+min(theta),0.2+max(theta))
    ax[1].set_ylim(-0.4+min(p),0.4+max(p))
    ax[1].plot(theta,p)
    ax[1].scatter([theta[t-1]],[p[t-1]],color="red")

anim = animation.FuncAnimation(fig,animate,frames=len(time),interval=10,blit=False)
writergif = animation.PillowWriter(fps=100)
anim.save('animation2.gif',writer=writergif)
plt.show()



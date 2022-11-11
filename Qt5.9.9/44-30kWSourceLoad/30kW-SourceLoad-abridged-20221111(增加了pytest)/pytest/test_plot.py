# This Python file uses the following encoding: utf-8
import numpy as np
import matplotlib.pyplot as plt

def main():
    x = np.linspace(-np.pi,np.pi,1000)
    y = np.cos(x)
    plt.plot(x,y,'b-*')
    plt.show()

if __name__ == '__main__':
    main()

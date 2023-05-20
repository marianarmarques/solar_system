import sys
import math

def shpereEquation():
    theta = 0
    radius = float(sys.argv[1])

    while(theta < 2 * math.pi):

        x = radius * math.cos(theta)
        y = radius * math.sin(theta)
        theta = theta + math.pi/5

        print('<point x="%f" y="0" z="%f"/>' % (x,y))

def elipseEquation(a, b):
    increment = (2 * a) / 10
    x_values = [al for al in (-a + i*increment for i in range(11))]

    for x in x_values[::2]:
        y = math.sqrt((1 - x**2/a**2) * b**2)
        print('<point x="{}" y="0" z="{}"/>'.format(x, y))

    for x in reversed(x_values[1::2]):
        y = -math.sqrt((1 - x**2/a**2) * b**2)
        print('<point x="{}" y="0" z="{}"/>'.format(x, y))

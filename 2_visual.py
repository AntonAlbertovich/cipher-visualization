import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt



objects = []
performance = []


with open("example_1.txt", "rb") as f:
    available = False
    temp = ""
    for line in f:
        try:
            this_per = int(line)
            temp = this_per
            available = True

        except ValueError:
            if(available == True):
                performance.append(temp)
                objects.append(line[:2])
                available = False
            else:
               continue 


f.close() 

y_pos = np.arange(len(objects))

plt.bar(y_pos, performance, align='center', alpha=1.0)
plt.xticks(y_pos, objects, rotation = 90)
plt.ylabel('Instances of Character')
plt.title('Character')
plt.show()

print(len(objects))
print(len(performance))
print(objects)
print(performance)

import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt



objects = []
performance = []
with open("example.txt","rb") as f:

    print("Output of Readlines after appending")
    contents = str(f.read())
    contents = contents.split(" ")
    for i in range(0, len(contents), 2):
        objects.append(contents[i])
        performance.append(contents[i+1])
f.close() 

y_pos = np.arange(len(objects))

plt.bar(y_pos, performance, align='center', alpha=1.0)
plt.xticks(y_pos, objects)
plt.ylabel('Instances of Character')
plt.title('Character')
plt.show()

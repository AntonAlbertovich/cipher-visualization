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
        try:
            performance.append(int(contents[i+1]))
        except ValueError:
            performance.append(1)

f.close() 
# Plot
plt.pie(performance, labels=contents, autopct='%1.1f%%', shadow=True, startangle=140)

plt.axis('equal')
plt.show()

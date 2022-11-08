import webbrowser

str1 = "https://drive.google.com/u/0/uc?id="
str2 = "&export=download"
links = [ ]
for i in links:
    webbrowser.open(str1 + i.split("/")[5] + str2)
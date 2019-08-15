#!/bin/python
import zipfile

for fileNum in range(0,100):
	nth = fileNum*5 + 1
	templateDocx = zipfile.ZipFile("./Rifa Casamento.docx")
	newDocx = zipfile.ZipFile("./FINAL/{:03d} Rifa Casamento".format(fileNum) + ".docx", "a")

	with open(templateDocx.extract("word/document.xml", "./temp/extracted/")) as tempXmlFile:
		tempXmlStr = tempXmlFile.read()

	while not tempXmlStr.find("XXX") == -1:
		tempXmlStr = tempXmlStr.replace("XXX", "{:03d}".format(nth), 1)
		tempXmlStr = tempXmlStr.replace("YYY", "{:03d}".format(nth), 1)
		nth += 1

	with open("./temp/temp.xml", "w+") as tempXmlFile:
		tempXmlFile.write(tempXmlStr)

	for file in templateDocx.filelist:
		if not file.filename == "word/document.xml":
			newDocx.writestr(file.filename, templateDocx.read(file))

	newDocx.write("./temp/temp.xml", "word/document.xml")

	templateDocx.close()
	newDocx.close()
#!/bin/python
import PyPDF2 as pdf

output_pdf = open('Rifa Casamento.pdf', 'wb')
wrote_pdf = pdf.PdfFileWriter() #the file object which is to be written

for fileNum in range(0,100):
	current_file_name = "./FINAL/PDF_FINAL/{:03d} Rifa Casamento".format(fileNum) + ".pdf"

	print("opening file " + current_file_name)
	current_pdf_file = open(current_file_name, 'rb')

	current_read_file = pdf.PdfFileReader(current_pdf_file) #the file object that has been read
	current_page_obj = current_read_file.getPage(0)

	print("writing to main object")
	wrote_pdf.addPage(current_page_obj)

print("writing to main file")
wrote_pdf.write(output_pdf)

output_pdf.close()
current_pdf_file.close()
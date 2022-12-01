from openpyxl import Workbook

from openpyxl import Workbook
import time

book = Workbook()
sheet = book.active
for i in range(3, 23):

    sheet[f'A{i}'] = 54
    sheet['B1'] = 43

    now = time.strftime("%x")
    sheet['C1'] = now

    book.save("libro/sample.xlsx")
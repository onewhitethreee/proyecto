import requests
from lxml import etree
import time


def header():
    header = {
        "User-Agent":
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36"
    }
    return header


def descargarLibro(url, header):
    url_original = 'https://www.casadellibro.com'
    html = requests.get(url, headers=header).text
    selector = etree.HTML(html)
    for i in range(3, 23):
        #/html/body/div[1]/div/div/div[1]/main/div/div/div/div[3]/div/div[3]/div[11]/div/div[2]/div/div[1]/a
        #/html/body/div[1]/div/div/div[1]/main/div/div/div/div[3]/div/div[3]/div[3]/div/div[2]/div/div[1]/a/
        href_url = selector.xpath(
            f'/html/body/div[1]/div/div/div[1]/main/div/div/div/div[3]/div/div[3]/div[{i}]/div/div[2]/div/div[1]/a/@href'
        )  #url de los libros
        new_url = url_original + href_url[0]
        new_url_html = requests.get(new_url, headers=header).text
        time.sleep(1)
        new_selector = etree.HTML(new_url_html)
        title = new_selector.xpath(
            'string(/html/body/div[1]/div/div/div[1]/main/div/div/div/div[3]/div/div[2]/div/h1/text())'
        ).strip()  #titulo del libro
        author = new_selector.xpath(
            'string(/html/body/div[1]/div/div/div[1]/main/div/div/div/div[3]/div/div[2]/div/div[1]/div/a/span[1])'
        ).strip()  #autor del libro
        iSBN = new_selector.xpath(
            'string(/html/body/div[1]/div/div/div[1]/main/div/div/div/div[3]/div/div[2]/div/div[2]/div[1]/span[2])'
        )  #ISBN del libro
        print('the title is: ', title)
        print('the author is: ', author)
        print('the ISBN is: ', iSBN)


if __name__ == "__main__":
    header = header()
    for i in range(3, 100):
        print(f'pagina {i}')
        url = f"https://www.casadellibro.com/ebooks/novela-contemporanea/narrativa-espanola/128007000/p{i}"  #literatura
        descargarLibro(url, header)
        time.sleep(2)
    #url = 'https://www.casadellibro.com/ebooks/autoayuda-y-espiritualidad/102000000'#ciencia
    #url = 'https://www.casadellibro.com/ebooks/historia/115000000'#historia, politicay sociologia
    #url = 'https://www.casadellibro.com/ebooks/salud-y-dietas/medicina-divulgativa/131006000 ciencia
    #url = 'https://www.casadellibro.com/ebooks/empresa/111000000' empresa
    #url = 'https://www.casadellibro.com/ebooks/infantil/infantil-5-a-6-anos/117004000' infantil

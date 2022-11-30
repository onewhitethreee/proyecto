import requests
from lxml import etree

def header():
    header = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36"}
    return header
def descargarLibro(url,header):
    html = requests.get(url,headers=header).text
    selector = etree.HTML(html)
    #/html/body/div[1]/div/div/div[1]/main/div/div/div/div[6]/div/div[3]/div[22]/div/div[2]/div/div[1]/a
    #/html/body/div[1]/div/div/div[1]/main/div/div/div/div[6]/div/div[3]/div[3]/div/div[2]/div/div[1]/a
    #https://www.casadellibro.com/ebooks/novela-contemporanea/narrativa-espanola/128007000/p3
    for i in range(3,23):
        titulo = selector.xpath(f'string(/html/body/div[1]/div/div/div[1]/main/div/div/div/div[6]/div/div[3]/div[{i}]/div/div[2]/div/div[1]/a)')#titulo de los libros
        print(titulo.strip())
        


if __name__ == "__main__":
    try:
        for i in range(1,100):
            print(f'pagina {i}')
            url = f"https://www.casadellibro.com/ebooks/novela-contemporanea/narrativa-espanola/128007000/p{i}"#literatura
            header = header()
            descargarLibro(url,header)
    except Exception as e:
        print(e)
    #url = 'https://www.casadellibro.com/ebooks/autoayuda-y-espiritualidad/102000000'#ciencia 
    #url = 'https://www.casadellibro.com/ebooks/historia/115000000'#historia, politicay sociologia
    #url = 'https://www.casadellibro.com/ebooks/salud-y-dietas/medicina-divulgativa/131006000 ciencia
    #url = 'https://www.casadellibro.com/ebooks/empresa/111000000' empresa
    #url = 'https://www.casadellibro.com/ebooks/infantil/infantil-5-a-6-anos/117004000' infantil
    
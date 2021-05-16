import requests
from bs4 import BeautifulSoup


def FindUrl(userInput):
    url = "https://novosibirsk.moba.ru/catalog/?q="
    check = " "
    for i in range(len(userInput)):
        if userInput[i] == " ":
            check += '+'
        else:
            check += userInput[i]
    url += check + "&s=%D0%9F%D0%BE%D0%B8%D1%81%D0%BA"
    if requests.get(url).status_code == 200:
        return url
    print("Error, the site is currently down")


def Parcer(url):
    dictname = dict()
    soup = BeautifulSoup(requests.get(url).text, 'html.parser')
    name = soup.find_all('a', class_="dark_link")
    price = soup.find_all('span', class_="price_value")
    for i in range(len(price)):
        dictname[name[i].text] = [price[i]]

    return dictname


if __name__ == '__main__':
    userInput = input("Model of phone: ")
    url = FindUrl(userInput)
    if url != "Error, the site is currently down":
        dictname = Parcer(url)
        for i in dictname:
            print(i,
                  int(dictname.get(i)[0].text.replace(" ", "")) + 12, "Рублей")
    print(url)

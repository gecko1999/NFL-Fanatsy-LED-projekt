from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import time
import serial

arduinoData = serial.Serial('com3', 9600)

chrome_options = Options()

chrome_options.add_argument("--headless")
chrome_options.add_argument("--window-size=1920x1080")

driver = webdriver.Chrome( executable_path=r'C:\Users\danie\PycharmProjects\Fantas\chromedriver.exe')

email = ''
passwort = ''

week = '8'
driver.get(f'https://fantasy.nfl.com/league/9441093/team/3/gamecenter?week={week}')
time.sleep(10)
username = driver.find_element(By.XPATH, '/html/body/div[1]/div/div/div[2]/div[3]/div/div[2]/input')
password = driver.find_element(By.XPATH, '/html/body/div[1]/div/div/div[2]/div[4]/div/div[2]/input')


username.send_keys(email)
password.send_keys(passwort)
driver.find_element(By.XPATH, '/html/body/div[1]/div/div/div[2]/div[5]/div').click()
print("Login sucessfull")
time.sleep(10)
try:
    driver.find_element(By.XPATH, '/html/body/div[1]/div/div/div/div[2]/div/button[3]').click()
except Exception:
    print('Cookies konnten nicht akzeptiert werden. Bitte neu starten')

driver.refresh()

qb = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[1]/td[7]/span'
rb1 = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[2]/td[7]/span'
rb2 = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[3]/td[7]/span'
wr1 = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[4]/td[7]/span'
wr2 = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[5]/td[7]/span'
te = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[6]/td[7]/span'
flex = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[7]/td[7]/span'
k = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[8]/td[7]/span'
de = '/html/body/div[3]/div[3]/div/div[1]/div/div[7]/div[2]/div[1]/div/div/div[2]/div/div/div[2]/div[1]/div/div/div[1]/div[1]/table/tbody/tr[9]/td[7]/span'


players = [qb, rb1, rb2, wr1, wr2, te, flex, k, de]
vorhaer = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

d = 0

def Ver??nderung(spieler, vorhaer, a, c):

    points = float(driver.find_element(By.XPATH, spieler).text)

    if points > vorhaer[c]:
        d = 1
        vorhaer[c] = points

    elif points < vorhaer[c]:
        d = 2
        vorhaer[c] = points

    elif points == vorhaer[c]:
        d = 0
        vorhaer[c] = points



    return str(a)+str(d)




while True:
    MESSAGE = Ver??nderung(players[0], vorhaer, 1, 0)+Ver??nderung(players[1], vorhaer, 2, 1)+Ver??nderung(players[2], vorhaer, 3, 2)+Ver??nderung(players[3], vorhaer, 4, 3)+Ver??nderung(players[4], vorhaer, 5, 4)+Ver??nderung(players[5], vorhaer, 6, 5)+Ver??nderung(players[6], vorhaer, 7, 6)+Ver??nderung(players[7], vorhaer, 8, 7)+Ver??nderung(players[8], vorhaer, 9, 8)
    print(MESSAGE)
    arduinoData.write(bytes(MESSAGE, 'UTF-8'))
    time.sleep(15)
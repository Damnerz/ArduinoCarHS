# Créé par user, le 19/10/2024 en Python 3.7

import time
import serial
import pyautogui

# Remplacez 'COM3' par le port de votre Arduino (sur Windows) ou '/dev/ttyUSB0' (sur Linux)
# Vous pouvez trouver le port correct dans l'IDE Arduino ou le gestionnaire de périphériques
arduino_port = 'COM4'  # Changez ceci selon votre configuration
baud_rate = 9600  # Doit correspondre à la vitesse de l'Arduino

# Initialisation de la connexion série
ser = serial.Serial(arduino_port, baud_rate)

def main():
    # Attendre que la connexion série soit établie
    time.sleep(2)  # Pause pour permettre à l'Arduino de se réinitialiser

    print("Prêt à recevoir des messages de l'Arduino...")
    print("Vous avez 5 secondes pour sélectionner la zone de texte...")
    time.sleep(5)  # Temps pour se préparer

    while True:
        if ser.in_waiting > 0:  # Vérifier si des données sont disponibles
            message = ser.readline().decode('utf-8').rstrip()  # Lire le message
            print(f"Message reçu : {message}")  # Afficher le message dans la console

            # Écrire le message en utilisant pyautogui
            pyautogui.typewrite(message)  # Taper le message
            pyautogui.press('enter')  # Appuyer sur 'Entrée' après le message

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("Programme interrompu.")
    finally:
        ser.close()  # Fermer la connexion série proprement

import csv
import random

def create_csv(num_divices):
    dados = [["ID", "Tempo para encher", "Tempo que permaneceu cheia"]];

    for i in range(num_divices):
        temp_encher = round(random.uniform(0.0, 24.0), 2)
        tempo_permanecer_cheia = round((24.0 - temp_encher), 2)

        dados.append([f"Lixeira_{i}", temp_encher, tempo_permanecer_cheia])

    return dados

def save_csv(file_name, dados):
    with open(file_name, mode = "w", newline = '', encoding= 'utf-8') as file_csv:
        write_csv = csv.writer(file_csv)
        write_csv.writerows(dados)


save_csv(input("Nome do arquivo:") + ".csv", create_csv(int(input("Numero de dispositivos:"))))

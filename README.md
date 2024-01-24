# Monitor de Consumo com o sensor SCT-013
<div align="center">
  <img src="https://github.com/alexxsouzaa/MonitorDeComsumo_SCT013/assets/132787362/e72e8c8a-1644-4ca8-bd31-45557f8f7d18" alt="Monitor_de_Consumo_com_o_sensor_SCT-013">
</div>

Este projeto consiste em um dispositivo de monitoramento de consumo de energia baseado no ESP32, utilizando o sensor de corrente SCT-013, um sensor de temperatura, um display OLED de 1.3 polegadas e comunicação sem fio via LoRa.

## Funcionalidades Principais

- **Monitoramento de Consumo de Energia:** Utiliza o sensor de corrente SCT-013 para medir a corrente elétrica, permitindo o monitoramento preciso do consumo de energia.

- **Sensor de Temperatura:** Possui um sensor de temperatura para aferir a temperatura ambiente e incorporar esse dado às informações coletadas.

- **Display OLED:** Apresenta informações de corrente, potência, tensão e temperatura em tempo real em um display OLED de 1.3 polegadas para fácil visualização.

- **Comunicação LoRa:** Os dados coletados são transmitidos através de uma rede sem fio LoRa, proporcionando uma solução eficiente e de longo alcance.

## Componentes Utilizados

- ESP32: Plataforma de desenvolvimento IoT poderosa e versátil.
- SCT-013: Sensor de corrente não invasivo.
- Sensor de Temperatura: Utilizado para medir a temperatura ambiente.
- Display OLED 1.3": Fornece uma interface intuitiva para visualização dos dados.
- Módulo LoRa: Possibilita a transmissão de dados de forma eficiente em longas distâncias.

## Configuração e Uso

1. Clone este repositório.
2. Configure as bibliotecas necessárias no Arduino IDE.
3. Conecte os componentes conforme o esquema elétrico fornecido.
4. Carregue o código para o ESP32.
5. Monitore os dados no display OLED e/ou receba os dados através da rede LoRa.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir problemas (issues) ou enviar pull requests para melhorar este projeto.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).

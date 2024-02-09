#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

double calcularMenor(double *faturamento, int tamanho)
{
    double menor = faturamento[0];
    for (int i = 1; i < tamanho; i++) {
        if (faturamento[i] < menor) {
            menor = faturamento[i];
        }
    }
    return menor;
}
double calcularMaior(double *faturamento, int tamanho)
{
    double maior = faturamento[0];
    for (int i = 1; i < tamanho; i++) {
        if (faturamento[i] > maior) {
            maior = faturamento[i];
        }
    }
    return maior;
}

int main()
{
    const char *dados_faturamento = "[{\"dia\":1,\"valor\":22174.1664},"
                                    "{\"dia\":2,\"valor\":24537.6698},"
                                    "{\"dia\":3,\"valor\":26139.6134},"
                                    "{\"dia\":4,\"valor\":0.0},"
                                    "{\"dia\":5,\"valor\":0.0},"
                                    "{\"dia\":6,\"valor\":26742.6612},"
                                    "{\"dia\":7,\"valor\":0.0},"
                                    "{\"dia\":8,\"valor\":42889.2258},"
                                    "{\"dia\":9,\"valor\":46251.174},"
                                    "{\"dia\":10,\"valor\":11191.4722},"
                                    "{\"dia\":11,\"valor\":0.0},"
                                    "{\"dia\":12,\"valor\":0.0},"
                                    "{\"dia\":13,\"valor\":3847.4823},"
                                    "{\"dia\":14,\"valor\":373.7838},"
                                    "{\"dia\":15,\"valor\":2659.7563},"
                                    "{\"dia\":16,\"valor\":48924.2448},"
                                    "{\"dia\":17,\"valor\":18419.2614},"
                                    "{\"dia\":18,\"valor\":0.0},"
                                    "{\"dia\":19,\"valor\":0.0},"
                                    "{\"dia\":20,\"valor\":35240.1826},"
                                    "{\"dia\":21,\"valor\":43829.1667},"
                                    "{\"dia\":22,\"valor\":18235.6852},"
                                    "{\"dia\":23,\"valor\":4355.0662},"
                                    "{\"dia\":24,\"valor\":13327.1025},"
                                    "{\"dia\":25,\"valor\":0.0},"
                                    "{\"dia\":26,\"valor\":0.0},"
                                    "{\"dia\":27,\"valor\":25681.8318},"
                                    "{\"dia\":28,\"valor\":1718.1221},"
                                    "{\"dia\":29,\"valor\":13220.495},"
                                    "{\"dia\":30,\"valor\":8414.61}]";


    json_object *json = json_tokener_parse(dados_faturamento);
    int tamanho = json_object_array_length(json);

    double *faturamento = malloc(tamanho * sizeof(double));


    for (int i = 0; i < tamanho; i++)
    {
        json_object *obj = json_object_array_get_idx(json, i);
        json_object *valor_obj;
        if (json_object_object_get_ex(obj, "valor", &valor_obj))
        {
            faturamento[i] = json_object_get_double(valor_obj);
        }
    }

    double menor = calcularMenor(faturamento, tamanho);
    printf("Menor valor de faturamento: %.4f\n", menor);

    double maior = calcularMaior(faturamento, tamanho);
    printf("Maior valor de faturamento: %.4f\n", maior);


    double soma = 0.0;
    int diasComFaturamento = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (faturamento[i] > 0.0)
        {
            soma += faturamento[i];
            diasComFaturamento++;
        }
    }
    double mediaMensal = diasComFaturamento > 0 ? soma / diasComFaturamento : 0.0;

    int diasAcimaDaMedia = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (faturamento[i] > mediaMensal)
        {
            diasAcimaDaMedia++;
        }
    }
    printf("Dias com faturamento acima da media: %d\n", diasAcimaDaMedia);

    free(faturamento);
    json_object_put(json);

    return 0;
}

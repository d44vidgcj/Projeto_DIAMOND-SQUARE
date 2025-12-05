#ifndef MAPA_ALTITUDES_H
#define MAPA_ALTITUDES_H

#include <cstddef>
#include "paleta.h"
#include "imagem.h"

class MapaAltitudes {
private:
    size_t tamanho;
    double* altitudes;
    
    // Métodos auxiliares (já existentes)
    size_t calcularIndice(size_t lin, size_t col) const;
    void liberar();
    void alocar(size_t tam);
    void etapaDiamond(size_t x, size_t y, size_t passo, double amplitude);
    void etapaSquare(size_t x, size_t y, size_t passo, double amplitude);
    double obterAltitudaSegura(int lin, int col, double padrao) const;
    
    // Novos métodos auxiliares para geração de imagem
    Cor mapearAltitudeCor(double altitude, const Paleta& paleta) const;
    double calcularSombreamento(size_t lin, size_t col) const;

public:
    // Construtores e destrutor (já existentes)
    MapaAltitudes();
    explicit MapaAltitudes(int N);
    ~MapaAltitudes();
    
    // Métodos já existentes
    void gerar(int N, double rugosidade);
    double obterAltitude(size_t lin, size_t col) const;
    size_t obterLinhas() const;
    size_t obterColunas() const;
    bool salvar(const char* nomeArquivo) const;
    bool ler(const char* nomeArquivo);
    
    // NOVO: Método principal da Etapa 4
    Imagem gerarImagem(const Paleta& paleta, bool aplicarSombreamento = true) const;
};

#endif
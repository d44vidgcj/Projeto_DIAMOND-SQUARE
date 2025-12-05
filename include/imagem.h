#ifndef IMAGEM_H
#define IMAGEM_H

#include <cstddef>

// Tipo Pixel - estrutura para representar um pixel RGB
struct Pixel {
    unsigned char r, g, b;
    
    // Construtor padrão - pixel preto
    Pixel() : r(0), g(0), b(0) {}
    
    // Construtor com valores RGB
    Pixel(unsigned char r, unsigned char g, unsigned char b) 
        : r(r), g(g), b(b) {}
};

class Imagem {
private:
    size_t largura;
    size_t altura;
    Pixel* pixels;  // Array único para armazenar todos os pixels
    
    // Método auxiliar para calcular índice no array
    size_t calcularIndice(size_t x, size_t y) const;
    
    // Método auxiliar para liberar memória
    void liberar();
    
    // Método auxiliar para alocar memória
    void alocar(size_t larg, size_t alt);

public:
    // Construtores
    Imagem();  // Construtor padrão - imagem vazia
    Imagem(size_t largura, size_t altura);  // Construtor com dimensões
    
    // Destrutor
    ~Imagem();
    
    // Métodos de consulta
    size_t obterLargura() const;
    size_t obterAltura() const;
    
    // Operador de acesso aos pixels (x=coluna, y=linha)
    Pixel& operator()(size_t x, size_t y);
    const Pixel& operator()(size_t x, size_t y) const;
    
    // Métodos de I/O
    bool lerPPM(const char* nomeArquivo);
    bool salvarPPM(const char* nomeArquivo) const;
};

#endif
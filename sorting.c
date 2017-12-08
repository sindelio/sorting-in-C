#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void insertion_sort(int v[], int n){ //ok
    int i, j, x;
    for (i = 1; i < n; i++){
        x = v[i];
        j = i - 1;
        while ((j >= 0) && (x < v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void selection_sort_improved(int v[], int n){ //ok
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;
    }
}

void bubble_sort_improved(int v[], int n){ //ok
    int i, j, aux, trocou = 1;
    for (i = n - 1; (i > 0 && trocou); i--){
        trocou = 0;
        for (j = 0; j < i; j++){
            if (v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                trocou = 1;
            }
        }
    }
}

void rearranjar_heap(int v[], int i, int tamanho_do_heap){
    int esq, dir, maior, aux;
    esq = 2 * i + 1;
    dir = 2 * i + 2;
    if((esq < tamanho_do_heap) && (v[esq] > v[i])){
        maior = esq;
    }
    else{
        maior = i;
    }
    if((dir < tamanho_do_heap) && (v[dir] > v[maior])){
        maior = dir;
    }
    if(maior != i){
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        rearranjar_heap(v, maior, tamanho_do_heap);
    }
}

void construir_heap(int v[], int n){
    int i;
    for (i = n/2-1; i >= 0; i--){
        rearranjar_heap(v, i, n);
    }
}

void heapsort(int v[], int n){ //ok
    int i, aux, tamanho_do_heap;
    construir_heap(v, n);
    tamanho_do_heap = n;
    for(i = n - 1; i > 0; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        tamanho_do_heap--;
        rearranjar_heap(v, 0, tamanho_do_heap);
    }
}

void intercala(int v[], int p, int q, int r){
    int i = p, j = q, k = 0, *w;
    w = malloc((r - p)*sizeof(int));
    while (i < q && j < r) {
        if (v[i] <= v[j]){
            w[k++] = v[i++];
        }
        else{
            w[k++] = v[j++];
        }
    }
    while (i < q){
        w[k++] = v[i++];
    }
    while (j < r){
        w[k++] = v[j++];
    }
    for (i = p; i < r; ++i){
        v[i] = w[i-p];
    }
    free(w);
}

void mergesort(int v[], int p, int r){ //ok
    int q;
    if (p < r - 1){
        q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q, r);
        intercala(v, p, q, r);
    }
}

void quicksort(int v[], int inf, int sup){ //ok
    int aux, meio, pivo, i, j;
    if(inf < sup){
        meio = (inf + sup) / 2;
        pivo = v[meio];
        v[meio] = v[sup];
        v[sup] = pivo;
        i = inf - 1;
        j = sup;
        do{
            do{
                i++;
            } while(v[i] < pivo);
            do{
                j--;
            } while(v[j] > pivo && j > inf);
            if(i < j){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        } while(i < j);
        v[sup] = v[i];
        v[i] = pivo;
        quicksort(v, inf, i - 1);
        quicksort(v, i + 1, sup);
    }
}

void shellsort(int v[], int n){ //ok
    int h, x, i, j;
    for (h = 1; h < n; h = 3*h + 1){
        ;
    }
    while (h>1){
        h = h/3;
        for(i = h; i < n; i++) {
            x = v[i];
            j = i;
            while (j >= h && v[j-h] > x) {
                v[j] = v[j - h];
                j = j - h;
            }
            v[j] = x;
        }
    }
}

void inverse_sort(int v[], int n){ //ok
    int i, aux, meio;
    meio = n / 2;
    for(i = 0; i < meio; i++){
        aux = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = aux;
    }
}

#   Autor: Henrique Coutinho Layber
#   Data: 14/06/2019

#!/bin/bash

if [[ $# -ne 4 ]]; then
    echo "# Informe a quantidade de buscas e as repeticoes, e o nome do arquivo executavel, e a entrada nessa ordem."
    echo "# autoTester Buscas Repeticoes fileExec fileInput"
    exit 1
fi

Busca=$1
Repeticoes=$2
Exec="$3"
In="$4"
aux=0

Out_Str=$(basename ${In} | awk -F"_" '{print $2 "" $3}')
idout=1
FileOut="${Out_Str}-${Repeticoes}Execs.txt"

# Resolvendo arquivo de saida
while [[ -e ${FileOut} ]]; do
    idout=$((idout+1))
    FileOut="${Out_Str}-${Repeticoes}Execs(${idout}).txt"
done

#echo "Comando = ${Exec} ${Busca} ${In}" >> ${FileOut}

while [[ ${aux} -lt ${Repeticoes} ]]; do
    #echo "--- Execução número ${aux} ---" >> ${FileOut}
    (${Exec} ${Busca} < ${In} | tee --append "${FileOut}")
    aux=$((aux+1))
done

echo "---- Tudo finalizado! Saindo ... ----"
exit 0

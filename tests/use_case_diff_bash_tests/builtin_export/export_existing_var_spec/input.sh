export_myvar=abc
export export_myvar
bash -c 'env | grep export_myvar'

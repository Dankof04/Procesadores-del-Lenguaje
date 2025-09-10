#!/bin/bash

# commit.sh - Script para automatizar git add, commit y push

# Pedir mensaje de commit al usuario
read -p "Introduce el mensaje del commit: " mensaje

# Añadir todos los cambios
git add .

# Hacer commit con el mensaje proporcionado
git commit -m "$mensaje"

# Hacer push a la rama principal (main)
git push origin main

echo "✅ Commit y push completados con el mensaje: '$mensaje'"

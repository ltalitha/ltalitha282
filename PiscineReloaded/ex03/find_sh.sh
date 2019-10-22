find . -type f -name "*.sh" | cut -d . -f 1,2 | rev | cut -d / -f1 | rev 

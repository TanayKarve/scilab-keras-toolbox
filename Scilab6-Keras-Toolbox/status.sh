echo > .keras-status.log
gnome-terminal --geometry=84x20 --title="Training..." -e "tail -f \".keras-status.log\""

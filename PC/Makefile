.PHONY: gui
ui: main_window.py

main_window.py: ui/main_window.ui
	pyuic5 ui/main_window.ui -o main_window.py

.PHONY: clean
clean:
	rm -f main_window.py

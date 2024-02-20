# Шпаргалка по виджетам и другим классам Qt
## QMessageBox (Всплывающее окно с сообщением)
```
#include <QMessageBox>
…
QMessageBox msgb;
msgb.setText(text);
msgb.exec();
```

## QString (в примерах leInput – виджет типа LineEdit с objectName = leInput)
1.	Преобразование из строки в число:
```
QString s = ui->leInput->text();
bool ok;
double x = s.toDouble(&ok); // int x = s.toInt(&ok);
if (ok) {…}
```
2.	Преобразование из числа в строку:
```
double x = 123.45;
QString s = QString::number(x, 'f', 2); // в скобках - число, формат ('g', 'G', 'f', 'F', 'e', 'E')
										// и число знаков после запятой
										// два последних параметра – не обязательны
```
3.	Преобразование из QString в const char* и обратно:
```
QString s = ui->leInput->text();
const char* c_str = s.toLocal8Bit().data();
…
QString s1 = QString::fromLocal8Bit(c_str);
```
4.	Разделение строки по разделителю:
```
QStringList parts = ui->leInput->text().split(" "); // здесь разделитель - пробел
for (int i = 0; i < parts.length();  i++) {
	// что-то делаем с parts[i], которые являются QString
}
```
## QListWidget (в примерах lwList – виджет типа ListWidget с objectName = lwList)
1.	Очистка:
```
ui->lwList->clear();
```
2.	Добавить элемент в конец:
```
ui->lwList->addItem(строка типа QString);
```
3.	Проверить, есть ли выделенный элемент:
```
if (ui->lwList->selectionModel()->hasSelection())
```
4.	Номер строки, которую пользователь выделил последней:
```
int index = ui->lwList->selectionModel()->currentIndex().row();
// или
int index = ui->lwFIO->currentIndex().row();
// или
int index = ui->lwList->currentRow();
```
5.	Установить/снять выделение строки:
```
ui->lwList->item(индекс строки)->setSelected(true/false);
```
6.	Получить текст строки по индексу:
```
QString s = ui->lwList->item(индекс)->text();
```
7.	Задать текст выделенной строки:
```
ui->lwList->item(индекс)->setText(строка);
```

#include <iostream>
#include <vector>
#include <string>

const char CURSOR = '|';

struct Revision
{
	std::string text;
	int cursorIndex;

	Revision(){
		this->text = CURSOR;
		this->cursorIndex = 0;
	}

};


struct TextEditor
{

	std::vector<Revision> revisions; // store all revisions for undo
	int currentRevision;

	TextEditor(){

		this->currentRevision = 0;
		Revision r;

		this->revisions.push_back(r); 

		this->displayText("Start with empty text");
		
	}

	void displayText(std::string funcName){

		Revision revision = this->revisions[this->currentRevision];
		std::cout << funcName << std::endl;
		std::cout << "text = \"" << revision.text << "\"" << std::endl;
	}
	/*
	* Move cursor index to left
	*/
	void moveCursorLeft(){

		Revision r = this->revisions[this->currentRevision];
		char leftChar;

		if(r.cursorIndex > 0){
			leftChar = r.text[r.cursorIndex-1];
			r.text[r.cursorIndex-1] = CURSOR;
			r.text[r.cursorIndex] = leftChar;
			r.cursorIndex --;

			this->revisions.push_back(r);
			this->currentRevision ++;


		}

		this->displayText("moveCursorLeft()");




	}

	/*
	* Move cursor index to right
	*/
	void moveCursorRight(){

		Revision r = this->revisions[this->currentRevision];
		char rightChar;

		if(r.cursorIndex < r.text.size() -1){

			rightChar = r.text[r.cursorIndex+1];
			r.text[r.cursorIndex+1] = CURSOR;
			r.text[r.cursorIndex] = rightChar;
			r.cursorIndex ++;

			this->revisions.push_back(r);
			this->currentRevision ++;
		}

		this->displayText("moveCursorRight()");

	}

	/*
	* Insert the char right before cursor
	*/

	void insertCharacter(char ch){

		Revision r = this->revisions[this->currentRevision];
		r.text[r.cursorIndex] = ch;
		r.text += "|";
		r.cursorIndex++;

		this->revisions.push_back(r); // new revision become current revision
		this->currentRevision ++;

		std::string s = "insertCharacter('";
		s+= ch;
		s+= "')";
		this->displayText(s);
	}

	/*
	* delete the char right before cursor
	*/
	void backspace(){

		Revision r = this->revisions[this->currentRevision];
		if(r.text.size() > 1 && r.cursorIndex > 0){
				r.text.erase(r.cursorIndex - 1, 1);		
				r.cursorIndex --;

				this->revisions.push_back(r);
				this->currentRevision++;
		}

		this->displayText("backspace()");


	}

	/*
	* Undo last edit
	*/

	void undo(){

		if(this->currentRevision > 0){
			this->currentRevision--;
		}

		this->displayText("undo()");
	}
	
};



void beginTest(){

	TextEditor editor;

	editor.insertCharacter('a');
	editor.insertCharacter('b');
	editor.insertCharacter('c');

	editor.moveCursorLeft();
	editor.moveCursorLeft();
	editor.moveCursorLeft();

	editor.backspace();
	editor.moveCursorLeft();

	editor.undo();
	editor.undo();
	editor.undo();
	editor.undo();
	editor.undo();




}
int main(int argc, char const *argv[]){
	
	beginTest();

	return 0;
}
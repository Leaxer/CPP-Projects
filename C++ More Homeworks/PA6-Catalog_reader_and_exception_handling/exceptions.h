#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class Exception{
	public:
};

class MissingFieldException : public Exception{
    public:
        MissingFieldException(string thisMessage) {message = thisMessage;}
        string getMessage() const {return message;}
    private:
        string message;
};

class DuplicateEntryException : public Exception{
    public:
        DuplicateEntryException(string thisMessage) {message = thisMessage;}
        string getMessage() const {return message;}
    private:
        string message;
};

class WrongCommandException : public Exception{
    public:
        WrongCommandException(string thisMessage) {message = thisMessage;}
        string getMessage() const {return message;}
    private:
        string message;
};

#endif
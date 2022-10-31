#include "CFile.h"
namespace fs = experimental::filesystem;

CFile::CFile(const fs::path& rFilePath, const string& rType) {
    mActualPath = rFilePath;
    mName = rFilePath.filename().c_str();
    struct stat fileInfo;
    stat(rFilePath.c_str(), &fileInfo);
    mSize = fileInfo.st_size;
    mType = rType;
}

CFile::~CFile() = default;

uintmax_t CFile::getSize() const {
    return mSize;
}

string CFile::getName() const {
    return mName;
}

string CFile::getType() const {
    return mType;
}

void CFile::Print(ostream &os) const {
    os  << setw(40)<< left << getName() << setw(10) <<left << getType() <<setw(17) << left<< getSizeHR();
}

ostream &operator<<(ostream &os, const CFile &parent) {
    parent.Print(os);
    return os;
}

string CFile::getSizeHR( ) const {
    int i = 0;
    string hr = {};
    double mantissa = mSize;
    for (; mantissa >= 1024.; mantissa /= 1024., ++i) { }
    mantissa = std::ceil(mantissa * 10.) / 10.;
    hr += to_string((int)mantissa) + "BKMGTPE"[i];
    if(i != 0) hr+= "B";
    return hr;
}

 fs::path CFile::getActualPath() const {
    return mActualPath;
}


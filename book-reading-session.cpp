#include "book-reading-session.h"
#include "helper.h"
#include <sstream>
using std::string;
using std::ostringstream;
namespace BookReader {




	BookReadingSession::BookReadingSession() :
			BookReadingSession(nullptr) {
	}

	BookReadingSession::BookReadingSession(Book* book) :
			book(book), current_page(0), last_access_date(Helper::GetCurrentTimeDate()) {

	}
	string BookReadingSession::ToString() {
		ostringstream oss;
		oss << GetBook()->GetTitle() << " Page: " << PageIdxStr() << " - " << GetLastAccessDate();
		return oss.str();
	}

	string BookReadingSession::GetCurrentPageContent() {
		return book->GetPages()[current_page];
	}

	const Book* BookReadingSession::GetBook() const {
		return book;	// No set
	}

	const string& BookReadingSession::GetLastAccessDate() const {
		return last_access_date;
	}

	void BookReadingSession::ResetLastAccessDate() {	// More convenient
		last_access_date = Helper::GetCurrentTimeDate();
	}

	int BookReadingSession::GetCurrentPage() const {
		return current_page;
	}

	string BookReadingSession::PageIdxStr() {
		ostringstream oss;
		oss << GetCurrentPage() + 1 << "/" << book->GetPages().size();
		return oss.str();
	}

	void BookReadingSession::NextPage() {
		if (current_page < (int) book->GetPages().size() - 1)
			current_page++;
	}
	void BookReadingSession::PreviousPage() {
		if (current_page > 0)
			current_page--;
	}


}

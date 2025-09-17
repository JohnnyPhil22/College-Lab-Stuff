#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

// 🗓️ Date Class
class Date
{
private:
    // Define Data Members Here: month, day, year
    int month, day, year;

public:
    Date(int m = 1, int d = 1, int y = 2000)
    {
        month = m;
        day = d;
        year = y;
    }

    // Define Setters and Getters Here
    int getMonth() const
    {
        return month;
    }
    int getDay() const
    {
        return day;
    }
    int getYear() const
    {
        return year;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setYear(int y)
    {
        year = y;
    }

    void print() const
    {
        cout << month << "/" << day << "/" << year;
    }
};

// ⏰ Time Class
class Time
{
private:
    // Define Data Members Here: hour and minute
    int hour, minute;

public:
    Time(int h = 0, int m = 0)
    {
        hour = h;
        minute = m;
    }

    // Define setters and getters here
    int getHour() const
    {
        return hour;
    }
    int getMinute() const
    {
        return minute;
    }
    void setHour(int h)
    {
        hour = h;
    }
    void setMinute(int m)
    {
        minute = m;
    }

    Time addMinutes(int duration) const
    {
        int newMinute = minute + duration;
        int newHour = hour + newMinute / 60;
        newMinute %= 60;
        return Time(newHour, newMinute);
    }

    void print() const
    {
        cout << hour << ":" << (minute < 10 ? "0" : "") << minute;
    }
};

// 📩 Invitee Class
class Invitee
{
private:
    // Define data members here: email
    string email;

public:
    Invitee(string e)
    {
        email = e;
    }

    static bool isValidEmail(const string &email)
    {
        regex pattern("^[A-Za-z][A-Za-z0-9.]{2,}@csufresno.edu$");
        return regex_match(email, pattern);
    }

    string getEmail() const
    {
        return email;
    }

    void print() const
    {
        cout << email << " ";
    }
};

// 🎟️ Event Class
class Event
{
private:
    string title, location;
    Date date;
    Time startTime, endTime;
    vector<Invitee> invitees;

public:
    Event(string t, Date d, Time start, int duration, string loc)
    {
        title = t;
        date = d;
        startTime = start;
        endTime = start.addMinutes(duration);
        location = loc;
    }

    string getTitle() const
    {
        return title;
    }
    int getMonth() const
    {
        return date.getMonth();
    }

    void addInvitee(const string &email)
    {
        if (Invitee::isValidEmail(email))
        {
            invitees.emplace_back(email);
            cout << "Invitee added: " << email << endl;
        }
        else
        {
            cout << "Invalid email format: " << email << endl;
        }
    }

    void print() const
    {
        cout << "Event: " << title << " | Date: ";
        date.print();
        cout << " | Start Time: ";
        startTime.print();
        cout << " | End Time: ";
        endTime.print();
        cout << " | Location: " << location << endl;

        cout << "Invitees: ";
        for (const auto &invitee : invitees)
        {
            invitee.print();
        }
        cout << endl;
    }
};

// 📅 Calendar Class
class Calendar
{
private:
    vector<Event> events;

public:
    // ✅ Add Event
    void addEvent(const Event &event)
    {
        events.push_back(event);
        cout << "Event added: " << event.getTitle() << endl;
    }

    // ✅ Drop Event
    void dropEvent(const string &title)
    {
        for (auto it = events.begin(); it != events.end(); ++it)
        {
            if (it->getTitle() == title)
            {
                cout << "Event removed: " << it->getTitle() << endl;
                events.erase(it);
                return;
            }
        }
        cout << "Event not found: " << title << endl;
    }

    // ✅ Search Events by Month
    void searchEvent(int month)
    {
        cout << "Events in month " << month << ":" << endl;
        for (const auto &event : events)
        {
            if (event.getMonth() == month)
            {
                event.print();
            }
        }
    }
};

// 🏁 Main Function
int main()
{
    Calendar calendar;

    Event event1("Meeting", Date(2, 10, 2025), Time(14, 30), 60, "Room 101");
    event1.addInvitee("john@csufresno.edu");
    event1.addInvitee("alice@csufresno.edu");

    Event event2("Conference", Date(3, 15, 2025), Time(9, 0), 120, "Hall A");
    event2.addInvitee("mark123@csufresno.edu");

    calendar.addEvent(event1);
    calendar.addEvent(event2);

    cout << "\nSearching events in February:\n";
    calendar.searchEvent(2);

    cout << "\nDeleting 'Meeting' event:\n";
    calendar.dropEvent("Meeting");

    cout << "\nSearching events in February after deletion:\n";
    calendar.searchEvent(2);

    return 0;
}

from tkinter import *
from tkinter import messagebox
from random import randint, choice, shuffle
import pyperclip
import re
from abc import ABC, abstractmethod
from enum import Enum
from datetime import datetime

class PasswordStrength(Enum):
    WEAK = "Weak"
    STRONG = "Strong"

# Abstract Base Class
class Validator(ABC):
    @abstractmethod
    def validate(self, value) -> bool:
        pass

    @abstractmethod
    def error_message(self) -> str:
        pass


class PasswordGenerator(ABC):
    @abstractmethod
    def generate(self) -> str:
        pass


class StorageManager(ABC):
    @abstractmethod
    def save(self, website, email, password):
        pass


class NotificationService(ABC):
    @abstractmethod
    def notify(self, title, message):
        pass

# Validator
class LengthValidator(Validator):
    def validate(self, password):
        return len(password) >= 8

    def error_message(self):
        return "Password must be at least 8 characters long."


class DigitValidator(Validator):
    def validate(self, password):
        return bool(re.search(r"\d", password))

    def error_message(self):
        return "Password must contain at least one digit."


class SymbolValidator(Validator):
    def validate(self, password):
        return bool(re.search(r"[!@#$%^&*()+]", password))

    def error_message(self):
        return "Password must contain at least one special character."


class LetterValidator(Validator):
    def validate(self, password):
        return bool(re.search(r"[A-Za-z]", password))

    def error_message(self):
        return "Password must contain alphabetic characters."

class StrongPasswordGenerator(PasswordGenerator):
    def generate(self):
        letters = list("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
        numbers = list("0123456789")
        symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

        password = (
            [choice(letters) for _ in range(randint(8, 10))] +
            [choice(numbers) for _ in range(randint(2, 4))] +
            [choice(symbols) for _ in range(randint(2, 4))]
        )

        shuffle(password)
        return "".join(password)

class FileStorageManager(StorageManager):
    def save(self, website, email, password):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        with open("data.txt", "a") as file:
            file.write(f"{timestamp} | {website} | {email} | {password}\n")

class TkinterNotifier(NotificationService):
    def notify(self, title, message):
        messagebox.showinfo(title, message)

class PasswordAnalyzer:
    def __init__(self, validators):
        self.validators = validators

    def analyze(self, password):
        for validator in self.validators:
            if not validator.validate(password):
                return PasswordStrength.WEAK
        return PasswordStrength.STRONG

    def failure_reasons(self, password):
        return [
            v.error_message()
            for v in self.validators
            if not v.validate(password)
        ]

class PasswordManagerController:
    def __init__(self, generator, storage, analyzer, notifier):
        self._generator = generator
        self._storage = storage
        self._analyzer = analyzer
        self._notifier = notifier

    def generate_password(self):
        password = self._generator.generate()
        pyperclip.copy(password)
        return password

    def save_credentials(self, website, email, password):
        strength = self._analyzer.analyze(password)

        if strength == PasswordStrength.WEAK:
            reasons = "\n".join(self._analyzer.failure_reasons(password))
            return False, reasons

        self._storage.save(website, email, password)
        return True, "Password saved successfully."

    def force_save(self, website, email, password):
        self._storage.save(website, email, password)

class PasswordManagerApp:
    def __init__(self, controller):
        self._controller = controller
        self._window = Tk()
        self._window.title("Advanced Password Manager")
        self._window.config(padx=50, pady=50)
        self._build_ui()

    def _build_ui(self):
        canvas = Canvas(self._window, width=200, height=200)

        try:
            self.logo = PhotoImage(file="logo.png")
            canvas.create_image(100, 100, image=self.logo)
        except:
            pass

        canvas.grid(row=0, column=1)

        Label(self._window, text="Website").grid(row=1, column=0)
        Label(self._window, text="Email / Username").grid(row=2, column=0)
        Label(self._window, text="Password").grid(row=3, column=0)

        self.website_entry = Entry(self._window, width=35)
        self.website_entry.grid(row=1, column=1, columnspan=2)
        self.website_entry.focus()

        self.email_entry = Entry(self._window, width=35)
        self.email_entry.grid(row=2, column=1, columnspan=2)
        self.email_entry.insert(0, "AliPythonDev@gmail.com")

        self.password_entry = Entry(self._window, width=21)
        self.password_entry.grid(row=3, column=1)

        Button(self._window, text="Generate Password",
               command=self._on_generate).grid(row=3, column=2)

        Button(self._window, text="Save",
               width=36,
               command=self._on_save).grid(row=4, column=1, columnspan=2)

    def _on_generate(self):
        password = self._controller.generate_password()
        self.password_entry.delete(0, END)
        self.password_entry.insert(0, password)

    def _on_save(self):
        website = self.website_entry.get()
        email = self.email_entry.get()
        password = self.password_entry.get()

        if not website or not email or not password:
            messagebox.showerror("Error", "All fields are required")
            return

        success, message = self._controller.save_credentials(
            website, email, password
        )

        if success:
            messagebox.showinfo("Success", message)
            self.website_entry.delete(0, END)
            self.password_entry.delete(0, END)
            self.website_entry.focus()
        else:
            proceed = messagebox.askyesno(
                "Weak Password",
                f"{message}\n\nDo you still want to save?"
            )
            if proceed:
                self._controller.force_save(website, email, password)
                self.website_entry.delete(0, END)
                self.password_entry.delete(0, END)
                self.website_entry.focus()

if __name__ == "__main__":
    validators = [
        LengthValidator(),
        DigitValidator(),
        SymbolValidator(),
        LetterValidator()
    ]

    analyzer = PasswordAnalyzer(validators)

    controller = PasswordManagerController(
        generator=StrongPasswordGenerator(),
        storage=FileStorageManager(),
        analyzer=analyzer,
        notifier=TkinterNotifier()
    )

    app = PasswordManagerApp(controller)
    app._window.mainloop()
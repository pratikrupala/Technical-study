%define buildroot %{_topdir}/%{name}-%{version}-root

BuildRoot:	%{buildroot}
Name:		rpmtest
Version:	1.0
Release:	1
Source:		rpmtest.tar.gz
Summary:	RPM creation experiment

Group:		Experimental
License:	GPL

%description
This whole setup is to try out creation of RPM and test it.

%prep
%setup -q


%build
make


%install
make install DESTDIR=%{buildroot}

%files
%defattr(-,root,root)
/usr/bin/rpm-test

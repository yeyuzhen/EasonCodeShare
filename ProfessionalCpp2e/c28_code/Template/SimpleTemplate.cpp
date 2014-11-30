template <typename T>
SimpleTemplate<T>::SimpleTemplate(T& inObject) : mObject(inObject)
{
}

template <typename T>
const T& SimpleTemplate<T>::get() const
{
	return mObject;
}

template <typename T>
void SimpleTemplate<T>::set(T& inObject)
{
	mObject = inObject;
}

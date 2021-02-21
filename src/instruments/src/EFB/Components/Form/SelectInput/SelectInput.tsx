import React from 'react';

/**
 * Options is array of options. Each option is an array, with the index 0 being the value and 1 being the display value
 * e.g [[0, "Value 1"], [1, "Value 2"]]
 * Options are displayed in order of list
 */
type SelectInputProps = {
	label: string,
	onChange?: (newValue: number | string) => void,
	defaultValue?: string | number,
	reverse?: boolean, // Flips label/input order
	options: (number | string)[][],
	dropdownOnTop?: boolean, // Display dropdown above input instead of below
	className?: string
};
type SelectInputState = {
	value: string | number,
	showDropdown: boolean
};

export default class SelectInput extends React.Component<SelectInputProps, SelectInputState> {
    constructor(props: SelectInputProps) {
        super(props);

        let defaultOption = this.props.options.find((opt) => opt[0] == (this.props.defaultValue ?? 0));

        if (defaultOption === undefined) {
            defaultOption = [0, ''];
        }

        this.state = {
            value: defaultOption[1],
            showDropdown: false,
        };
    }

	private onClicked = () => {
	    this.setState((prevState) => {
	        const newState = { ...prevState };

	        newState.showDropdown = !prevState.showDropdown;

	        return newState;
	    });
	}

	private onOptionClicked = (option: (string | number)[]) => {
	    if (this.props.onChange) {
	        this.props.onChange(option[0]);
	    }

	    this.setState((prevState) => {
	        const newState = { ...prevState };

	        newState.value = option[1];

	        return newState;
	    });
	}

	private dropdownElements = (): JSX.Element[] => {
	    const optionElements: JSX.Element[] = [];

	    for (const option of this.props.options) {
	        optionElements.push((
	            <div className="p-5 border-t border-b border-white" onClick={() => this.onOptionClicked(option)}>
	                {option[1]}
    </div>
	        ));
	    }
	    return optionElements;
	}

	render() {
	    return (
	        <div className={`flex ${this.props.className} ${this.props.reverse ? 'flex-row-reverse' : 'flex-row'}`}>
	            <div className={`flex flex-grow m-2.5 items-center ${this.props.reverse ? 'justify-start' : 'justify-end'}`}>{this.props.label}</div>
	            <div className="flex items-center cursor-pointer relative" onClick={this.onClicked}>
	                <div className="w-28 text-lg bg-gray-900 flex rounded">
	                    <div className="px-3 py-1.5 flex-grow">{this.state.value}</div>
	                    <div className="flex bg-gray-500 p-1 items-center rounded rounded-l-none justify-center">v</div>
    </div>
	                {this.state.showDropdown && (
    <div className={`w-full border border-white bg-gray-900 rounded z-10 absolute transform ${
	                        this.props.dropdownOnTop ? 'top-0 -translate-y-full' : 'bottom-0 translate-y-full'}`}
	                    >
	                        { this.dropdownElements() }
	                    </div>
	                )}
    </div>
    </div>
	    );
	}
}

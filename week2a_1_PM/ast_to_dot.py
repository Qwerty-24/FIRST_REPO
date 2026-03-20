import json
import sys
import os


def add_nodes(dot, node, parent_id=None):
    """Recursively traverses the JSON AST and builds DOT nodes."""
    # Unique ID for each node based on memory address
    node_id = f"node_{id(node)}"

    # Extract node kind (e.g., FunctionDecl) and name if exists
    kind = node.get('kind', 'Unknown')
    label = kind
    if 'name' in node:
        label += f"\\n({node['name']})"

    # Add node definition with styling
    dot.append(f'  "{node_id}" [label="{label}"];')

    # Create edge from parent to current child
    if parent_id:
        dot.append(f'  "{parent_id}" -> "{node_id}";')

    # Recursively process children in the 'inner' list
    for child in node.get('inner', []):
        # Optional: Filter out nodes from system headers to keep graph clean
        # Only process nodes that belong to the main source file
        if 'loc' in child and 'includedFrom' in child['loc']:
            continue

        add_nodes(dot, child, node_id)


def main():
    # Check for correct number of arguments
    if len(sys.argv) != 3:
        print("Usage: python ast_to_dot.py <input_json> <output_dot>")
        print("Example: python ast_to_dot.py source.ast.json source.ast.dot")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    if not os.path.exists(input_path):
        print(f"Error: File '{input_path}' not found.")
        sys.exit(1)

    try:
        # Clang usually outputs UTF-8. Change to 'utf-16' if you encounter errors on Windows.
        with open(input_path, 'r', encoding='utf-8-sig') as f:
            data = json.load(f)

        # Initialize DOT file structure
        dot_output = [
            'digraph AST {',
            '  rankdir=TB;',
            '  node [shape=box, fontname="Courier", style=filled, fillcolor="#e1f5fe"];',
            '  edge [color="#37474f", penwidth=1.2];'
        ]

        # Start recursive processing
        add_nodes(dot_output, data)
        dot_output.append('}')

        # Write to file
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write('\n'.join(dot_output))

        print(f"Success: Converted '{input_path}' to '{output_path}'")

    except Exception as e:
        print(f"An unexpected error occurred: {e}")


if __name__ == "__main__":
    main()
